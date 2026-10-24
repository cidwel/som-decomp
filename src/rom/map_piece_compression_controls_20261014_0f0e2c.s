.setcpu "65816"
.segment "CODE"
.org $0E2C
map_control_0f0e2c:
    .byte $EC ; backreference distance high bits
    .byte $02 ; distance low bit/count
    .byte $C1 ; same-value copy count/distance
    .byte $E6 ; previous-row copy count
