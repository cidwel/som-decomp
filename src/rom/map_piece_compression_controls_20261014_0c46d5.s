.setcpu "65816"
.segment "CODE"
.org $46D5
map_control_0c46d5:
    .byte $C1 ; same-value copy count/distance
    .byte $E1 ; previous-row copy count
    .byte $C5 ; same-value copy count/distance
    .byte $ED ; backreference distance high bits
    .byte $02 ; distance low bit/count
