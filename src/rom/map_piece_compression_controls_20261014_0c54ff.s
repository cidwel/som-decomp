.setcpu "65816"
.segment "CODE"
.org $54FF
map_control_0c54ff:
    .byte $C4 ; same-value copy count/distance
    .byte $E7 ; previous-row copy count
    .byte $ED ; backreference distance high bits
    .byte $02 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $0D ; row-distance/count
