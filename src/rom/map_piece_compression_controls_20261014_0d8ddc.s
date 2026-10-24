.setcpu "65816"
.segment "CODE"
.org $8DDC
map_control_0d8ddc:
    .byte $E8 ; backreference distance high bits
    .byte $0E ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $90 ; row-distance/count
    .byte $C1 ; same-value copy count/distance
