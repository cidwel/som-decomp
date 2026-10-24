; Recovered Secret of Mana USA routine; behaviour documented in docs/event-menu-publication.md.
.setcpu "65816"
.smart
.a8
.i16

publish_native_menu_actor_text_and_palette = $2082
upload_complete_native_menu_oam_table = $1F5B
upload_complete_native_menu_tile_workspace = $25AD
upload_four_native_menu_description_rows = $279E

.segment "CODE"
.org $1E94
publish_pending_native_menu_tiles_oam_and_actor_color:
    .a8
    lda #$02
    bit a:$A20A
    beq publish_pending_native_menu_tiles_oam_and_actor_color_c01ead
    lda a:$A202
    .a8
    cmp #$05
    bne publish_pending_native_menu_tiles_oam_and_actor_color_c01eaa
    jsr publish_native_menu_actor_text_and_palette
    jsr upload_four_native_menu_description_rows
    bra publish_pending_native_menu_tiles_oam_and_actor_color_c01ead
publish_pending_native_menu_tiles_oam_and_actor_color_c01eaa:
    jsr upload_complete_native_menu_tile_workspace
publish_pending_native_menu_tiles_oam_and_actor_color_c01ead:
    .a8
    lda #$04
    bit a:$A20A
    beq publish_pending_native_menu_tiles_oam_and_actor_color_c01ecb
    jsr upload_complete_native_menu_oam_table
    .a8
    lda #$1E
    sta f:$002121
    lda a:$A22D
    sta f:$002122
    lda a:$A22E
    sta f:$002122
publish_pending_native_menu_tiles_oam_and_actor_color_c01ecb:
    .a8
    lda #$06
    trb a:$A20A
    rts
