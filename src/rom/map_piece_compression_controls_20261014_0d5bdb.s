.setcpu "65816"
.segment "CODE"
.org $5BDB
map_control_0d5bdb:
    .byte $E8 ; backreference distance high bits
    .byte $13 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $0F ; row-distance/count
    .byte $C6 ; same-value copy count/distance
