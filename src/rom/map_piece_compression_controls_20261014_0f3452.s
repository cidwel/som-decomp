.setcpu "65816"
.segment "CODE"
.org $3452
map_control_0f3452:
    .byte $F1 ; progressive-copy count
    .byte $C9 ; same-value copy count/distance
    .byte $EA ; backreference distance high bits
    .byte $02 ; distance low bit/count
    .byte $E3 ; previous-row copy count
