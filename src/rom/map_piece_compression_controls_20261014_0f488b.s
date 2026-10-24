.setcpu "65816"
.segment "CODE"
.org $488B
map_control_0f488b:
    .byte $F1 ; progressive-copy count
    .byte $C1 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $0B ; row-distance/count
