.setcpu "65816"
.segment "CODE"
.org $3437
map_control_0f3437:
    .byte $C9 ; same-value copy count/distance
    .byte $EA ; backreference distance high bits
    .byte $02 ; distance low bit/count
    .byte $E3 ; previous-row copy count
