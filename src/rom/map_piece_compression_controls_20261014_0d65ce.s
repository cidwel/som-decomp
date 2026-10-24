.setcpu "65816"
.segment "CODE"
.org $65CE
map_control_0d65ce:
    .byte $C6 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $0E ; row-distance/count
