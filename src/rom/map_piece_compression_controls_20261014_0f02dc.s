.setcpu "65816"
.segment "CODE"
.org $02DC
map_control_0f02dc:
    .byte $C3 ; same-value copy count/distance
    .byte $EE ; backreference distance high bits
    .byte $08 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $10 ; row-distance/count
