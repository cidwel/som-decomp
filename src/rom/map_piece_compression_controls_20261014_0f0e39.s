.setcpu "65816"
.segment "CODE"
.org $0E39
map_control_0f0e39:
    .byte $EC ; backreference distance high bits
    .byte $02 ; distance low bit/count
    .byte $C1 ; same-value copy count/distance
    .byte $E6 ; previous-row copy count
    .byte $DA ; same-value copy count/distance
