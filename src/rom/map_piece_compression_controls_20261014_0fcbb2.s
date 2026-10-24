.setcpu "65816"
.segment "CODE"
.org $CBB2
map_control_0fcbb2:
    .byte $E1 ; previous-row copy count
    .byte $EA ; backreference distance high bits
    .byte $02 ; distance low bit/count
    .byte $C1 ; same-value copy count/distance
