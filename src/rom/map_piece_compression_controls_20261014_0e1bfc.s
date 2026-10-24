.setcpu "65816"
.segment "CODE"
.org $1BFC
map_control_0e1bfc:
    .byte $EB ; backreference distance high bits
    .byte $02 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $8E ; row-distance/count
    .byte $C7 ; same-value copy count/distance
