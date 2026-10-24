; Recovered Secret of Mana USA routine; behaviour documented in docs/ui-native-normal-category-menu.md.
.setcpu "65816"
.smart
.a8
.i16

construct_native_controller_binding_page_and_reset_input_selection = $C76DAB

.segment "CODE"
.org $2AC2
near_call_native_controller_page_constructor:
    jsl f:construct_native_controller_binding_page_and_reset_input_selection
    rts
