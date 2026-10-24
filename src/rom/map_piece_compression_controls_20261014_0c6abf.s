.setcpu "65816"
.segment "CODE"
.org $6ABF
map_control_0c6abf:
    .byte $E0 ; previous-row copy escape
    .byte $08 ; row-distance/count
    .byte $C6 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $0B ; row-distance/count
