.setcpu "65816"
.segment "CODE"
.org $595D
map_control_0d595d:
    .byte $C6 ; same-value copy count/distance
    .byte $ED ; backreference distance high bits
    .byte $02 ; distance low bit/count
    .byte $EF ; backreference distance high bits
    .byte $82 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $14 ; row-distance/count
