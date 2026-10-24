.setcpu "65816"
.segment "CODE"
.org $FFAE
map_control_0dffae:
    .byte $EC ; backreference distance high bits
    .byte $02 ; distance low bit/count
    .byte $C1 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $13 ; row-distance/count
