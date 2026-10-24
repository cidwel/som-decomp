; Recovered Secret of Mana USA routine; behaviour documented in docs/ui-native-spell-item-page.md.
.setcpu "65816"
.smart
.a8
.i16

long_call_native_rendered_text_row_publication = $C75D96

.segment "CODE"
.org $29A5
render_native_selected_actor_page_caption:
    .a8
    lda #$57
    sta a:$9C00
    lda f:$0019FE
    sta a:$9C01
    .i16
    ldx #$0002
    phx
    .i16
    ldx #$6360
    stx a:$A18C
    .i16
    ldx #$0180
    stx a:$A191
    .i16
    ldx #$00C0
    stx a:$A199
    .a8
    lda #$01
    sta a:$A171
    plx
    jsl f:long_call_native_rendered_text_row_publication
    rtl
