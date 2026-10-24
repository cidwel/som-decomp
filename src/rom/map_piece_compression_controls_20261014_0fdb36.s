.setcpu "65816"
.segment "CODE"
.org $DB36
map_control_0fdb36:
    .byte $C2 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $81 ; row-distance/count
    .byte $ED ; backreference distance high bits
    .byte $02 ; distance low bit/count
