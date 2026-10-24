.setcpu "65816"
.segment "CODE"
.org $6204
map_control_0f6204:
    .byte $D7 ; same-value copy count/distance
    .byte $EC ; backreference distance high bits
    .byte $02 ; distance low bit/count
    .byte $EF ; backreference distance high bits
    .byte $82 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $14 ; row-distance/count
