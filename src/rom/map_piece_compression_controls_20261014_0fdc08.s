.setcpu "65816"
.segment "CODE"
.org $DC08
map_control_0fdc08:
    .byte $EF ; backreference distance high bits
    .byte $85 ; distance low bit/count
    .byte $C5 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $0B ; row-distance/count
    .byte $C3 ; same-value copy count/distance
