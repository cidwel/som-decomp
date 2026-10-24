.setcpu "65816"
.segment "CODE"
.org $BD6E
map_control_0fbd6e:
    .byte $C4 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $38 ; row-distance/count
    .byte $EA ; backreference distance high bits
    .byte $02 ; distance low bit/count
    .byte $E9 ; backreference distance high bits
    .byte $83 ; distance low bit/count
    .byte $E6 ; previous-row copy count
