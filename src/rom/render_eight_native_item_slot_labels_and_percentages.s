; Recovered Secret of Mana USA routine; behaviour documented in docs/ui-native-spell-item-page.md.
.setcpu "65816"
.smart
.a8
.i16

append_native_saved_slot_text_line_token = $538D
append_native_spell_percentage_from_actor_skill_field = $6619
append_two_native_saved_slot_text_space_tokens = $5386
jump_native_item_slot_description_index_api = $C06426
read_packed_native_weapon_skill_nibble_and_publish_glyph = $6679
render_native_saved_slot_text_rows_with_real_vblank = $5D9A

.segment "CODE"
.org $65B4
render_eight_native_item_slot_labels_and_percentages:
    .i16
    ldx #$0000
    .i16
    ldy #$0000
    .a8
    lda #$00
    sta a:$A175
render_eight_native_item_slot_labels_and_percentages_c765bf:
    stx a:$A178
    jsr append_two_native_saved_slot_text_space_tokens
    jsr append_two_native_saved_slot_text_space_tokens
    lda a:$CC54,Y
    inc
    beq render_eight_native_item_slot_labels_and_percentages_c765ea
    phy
    jsr read_packed_native_weapon_skill_nibble_and_publish_glyph
    .a8
    lda #$C5
    sta a:$9C00,X
    inx
    jsr append_native_spell_percentage_from_actor_skill_field
    ply
    jsl f:jump_native_item_slot_description_index_api
    sta a:$9C01,X
    .a8
    lda #$55
    sta a:$9C00,X
    inx
    inx
render_eight_native_item_slot_labels_and_percentages_c765ea:
    jsr append_native_saved_slot_text_line_token
    stx a:$A178
    iny
    lda a:$A175
    inc
    sta a:$A175
    .a8
    cmp #$08
    bne render_eight_native_item_slot_labels_and_percentages_c765bf
    phx
    .i16
    ldx #$7040
    stx a:$A18C
    .i16
    ldx #$0380
    stx a:$A191
    .i16
    ldx #$01C0
    stx a:$A199
    plx
    .a8
    lda #$08
    sta a:$A171
    jsr render_native_saved_slot_text_rows_with_real_vblank
    rts
