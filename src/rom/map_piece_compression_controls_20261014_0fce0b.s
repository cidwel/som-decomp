.setcpu "65816"
.segment "CODE"
.org $CE0B
map_control_0fce0b:
    .byte $E0 ; previous-row copy escape
    .byte $0F ; row-distance/count
    .byte $C2 ; same-value copy count/distance
