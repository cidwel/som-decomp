.setcpu "65816"
.segment "CODE"
.org $DB07
map_control_0fdb07:
    .byte $C1 ; same-value copy count/distance
    .byte $E1 ; previous-row copy count
    .byte $ED ; backreference distance high bits
    .byte $02 ; distance low bit/count
    .byte $E4 ; previous-row copy count
