.setcpu "65816"
.segment "CODE"
.org $D84A
map_control_0ed84a:
    .byte $E8 ; backreference distance high bits
    .byte $7F ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $7F ; row-distance/count
    .byte $C2 ; same-value copy count/distance
