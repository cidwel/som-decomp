.setcpu "65816"
.segment "CODE"
.org $164D
map_control_0e164d:
    .byte $C1 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $0B ; row-distance/count
