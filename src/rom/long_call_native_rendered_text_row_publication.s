; Recovered Secret of Mana USA routine; behaviour documented in docs/ui-native-spell-item-page.md.
.setcpu "65816"
.smart
.a8
.i16

render_native_saved_slot_text_rows_with_real_vblank = $5D9A

.segment "CODE"
.org $5D96
long_call_native_rendered_text_row_publication:
    jsr render_native_saved_slot_text_rows_with_real_vblank
    rtl
