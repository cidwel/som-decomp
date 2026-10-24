.setcpu "65816"
.segment "CODE"
.org $1F99
map_control_0e1f99:
    .byte $E0 ; previous-row copy escape
    .byte $0E ; row-distance/count
    .byte $C1 ; same-value copy count/distance
