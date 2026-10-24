.setcpu "65816"
.segment "CODE"
.org $8E3F
map_control_0f8e3f:
    .byte $E7 ; previous-row copy count
    .byte $EC ; backreference distance high bits
    .byte $02 ; distance low bit/count
    .byte $C3 ; same-value copy count/distance
    .byte $EE ; backreference distance high bits
    .byte $03 ; distance low bit/count
    .byte $E6 ; previous-row copy count
