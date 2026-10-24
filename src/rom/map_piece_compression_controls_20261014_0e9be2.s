.setcpu "65816"
.segment "CODE"
.org $9BE2
map_control_0e9be2:
    .byte $EF ; backreference distance high bits
    .byte $02 ; distance low bit/count
    .byte $D1 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $2B ; row-distance/count
