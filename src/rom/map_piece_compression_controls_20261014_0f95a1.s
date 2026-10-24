.setcpu "65816"
.segment "CODE"
.org $95A1
map_control_0f95a1:
    .byte $C3 ; same-value copy count/distance
    .byte $EF ; backreference distance high bits
    .byte $84 ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $11 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $09 ; row-distance/count
    .byte $EE ; backreference distance high bits
    .byte $02 ; distance low bit/count
