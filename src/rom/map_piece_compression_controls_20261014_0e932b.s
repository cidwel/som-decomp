.setcpu "65816"
.segment "CODE"
.org $932B
map_control_0e932b:
    .byte $EC ; backreference distance high bits
    .byte $02 ; distance low bit/count
    .byte $C2 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $13 ; row-distance/count
