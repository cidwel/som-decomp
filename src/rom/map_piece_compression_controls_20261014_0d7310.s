.setcpu "65816"
.segment "CODE"
.org $7310
map_control_0d7310:
    .byte $C9 ; same-value copy count/distance
    .byte $EF ; backreference distance high bits
    .byte $87 ; distance low bit/count
    .byte $ED ; backreference distance high bits
    .byte $02 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $10 ; row-distance/count
