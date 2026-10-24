.setcpu "65816"
.segment "CODE"
.org $575D
map_control_0f575d:
    .byte $D7 ; same-value copy count/distance
    .byte $C1 ; same-value copy count/distance
    .byte $E6 ; previous-row copy count
    .byte $EC ; backreference distance high bits
    .byte $02 ; distance low bit/count
