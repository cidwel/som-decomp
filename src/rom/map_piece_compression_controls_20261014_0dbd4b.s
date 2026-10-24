.setcpu "65816"
.segment "CODE"
.org $BD4B
map_control_0dbd4b:
    .byte $E9 ; backreference distance high bits
    .byte $02 ; distance low bit/count
    .byte $E1 ; previous-row copy count
    .byte $C4 ; same-value copy count/distance
