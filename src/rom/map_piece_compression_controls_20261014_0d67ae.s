.setcpu "65816"
.segment "CODE"
.org $67AE
map_control_0d67ae:
    .byte $D3 ; same-value copy count/distance
    .byte $EF ; backreference distance high bits
    .byte $02 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $0E ; row-distance/count
    .byte $C1 ; same-value copy count/distance
    .byte $E1 ; previous-row copy count
