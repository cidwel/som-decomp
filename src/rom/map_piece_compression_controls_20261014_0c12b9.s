.setcpu "65816"
.segment "CODE"
.org $12B9
map_control_0c12b9:
    .byte $ED ; backreference distance high bits
    .byte $02 ; distance low bit/count
    .byte $C2 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $11 ; row-distance/count
