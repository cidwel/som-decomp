; Recovered Secret of Mana USA routine; behaviour documented in docs/monster-ai-opcodes.md.
.setcpu "65816"
.smart
.a8
.i16

actor_script_refresh_appearance_preserving_context = $1660
advance_actor_script_1_bytes = $0121

.segment "CODE"
.org $1673
actor_script_toggle_flash_and_refresh_appearance:
    lda a:$0191,Y
    .a8
    and #$DF
    bne actor_script_toggle_flash_and_refresh_appearance_c116b5
    lda a:$01E9,Y
    sta a:$01E3,Y
    xba
    lda a:$01E4,Y
    .a8
    and #$80
    .a8
    eor #$80
    sta a:$01E4,Y
    bne actor_script_toggle_flash_and_refresh_appearance_c11694
    lda a:$01E8,Y
    sta a:$01E3,Y
    xba
actor_script_toggle_flash_and_refresh_appearance_c11694:
    .a8
    lda #$0C
    rep #$20
    sta f:$004202
    pha
    pla
    lda f:$004216
    sep #$20
    tax
    lda f:$D01000,X
    ora a:$01E4,Y
    sta a:$01E4,Y
    tyx
    phy
    jsr actor_script_refresh_appearance_preserving_context
    ply
actor_script_toggle_flash_and_refresh_appearance_c116b5:
    jmp advance_actor_script_1_bytes
