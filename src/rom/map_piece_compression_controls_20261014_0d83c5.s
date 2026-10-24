.setcpu "65816"
.segment "CODE"
.org $83C5
map_control_0d83c5:
    .byte $C1 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $0D ; row-distance/count
