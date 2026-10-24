.setcpu "65816"
.segment "CODE"
.org $D356
map_control_0dd356:
    .byte $EE ; backreference distance high bits
    .byte $02 ; distance low bit/count
    .byte $C3 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $17 ; row-distance/count
