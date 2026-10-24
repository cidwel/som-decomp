.setcpu "65816"
.segment "CODE"
.org $F18A
map_control_0ff18a:
    .byte $C4 ; same-value copy count/distance
    .byte $EC ; backreference distance high bits
    .byte $02 ; distance low bit/count
    .byte $E1 ; previous-row copy count
