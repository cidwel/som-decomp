; Six decoded swap-bit pairs of controller-button indices.
.setcpu "65816"
.segment "CODE"
native_controller_permutation_swap_index_pairs:
    .byte $00, $03, $01, $02, $01, $03, $00, $02
    .byte $00, $01, $02, $03
