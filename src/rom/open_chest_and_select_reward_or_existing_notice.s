; Recovered Secret of Mana USA routine; behaviour documented in docs/event-vm-chest-reward.md.
.setcpu "65816"
.smart
.a8
.i16

publish_existing_chest_class_notice = $C05907
random_byte_long_wrapper = $C0389C
restore_selected_effect_native_context_long = $E128
select_chest_gold_item_or_weapon_orb_and_publish = $E12C

.segment "CODE"
.org $E0B0
open_chest_and_select_reward_or_existing_notice:
    phd
    phb
    php
    rep #$30
    pha
    .a16
    lda #$0300
    tcd
    pla
    sta $83
    stx $85
    tay
    sep #$20
    lda a:$E190,Y
    .a8
    ora #$01
    sta a:$E190,Y
    .a8
    lda #$02
    sta a:$E1B4,Y
    lda a:$E1FB,Y
    .a8
    ora #$06
    sta a:$E1FB,Y
    lda $86
    lsr
    sta a:$E1F0,Y
    lda a:$E184,X
    pha
    lda a:$E1CA,X
    sta f:$004202
    .a8
    lda #$05
    sta f:$004203
    nop
    nop
    nop
    rep #$20
    lda f:$004216
    tax
    sep #$20
    pla
    bne open_chest_and_select_reward_or_existing_notice_c8e109
    lda f:$D03A51,X
    .a8
    and #$F0
    lsr
    cmp a:$E189,Y
    bcs open_chest_and_select_reward_or_existing_notice_c8e11a
open_chest_and_select_reward_or_existing_notice_c8e109:
    phx
    ldx $85
    stz a:$E1C8,X
    .a8
    lda #$FF
    sta a:$E183,X
    plx
    jsr select_chest_gold_item_or_weapon_orb_and_publish
    bra restore_selected_effect_native_context_long
open_chest_and_select_reward_or_existing_notice_c8e11a:
    jsl f:random_byte_long_wrapper
    .a8
    bit #$01
    bne open_chest_and_select_reward_or_existing_notice_c8e109
    ldx $85
    jsl f:publish_existing_chest_class_notice
