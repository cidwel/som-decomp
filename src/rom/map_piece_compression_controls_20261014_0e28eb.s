.setcpu "65816"
.segment "CODE"
.org $28EB
map_control_0e28eb:
    .byte $C6 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $0F ; row-distance/count
