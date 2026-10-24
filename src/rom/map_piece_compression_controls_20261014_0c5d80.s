.setcpu "65816"
.segment "CODE"
.org $5D80
map_control_0c5d80:
    .byte $D1 ; same-value copy count/distance
    .byte $D2 ; same-value copy count/distance
    .byte $EA ; backreference distance high bits
    .byte $02 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $35 ; row-distance/count
