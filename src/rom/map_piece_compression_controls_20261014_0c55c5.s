.setcpu "65816"
.segment "CODE"
.org $55C5
map_control_0c55c5:
    .byte $ED ; backreference distance high bits
    .byte $06 ; distance low bit/count
    .byte $C6 ; same-value copy count/distance
    .byte $E7 ; previous-row copy count
    .byte $ED ; backreference distance high bits
    .byte $02 ; distance low bit/count
