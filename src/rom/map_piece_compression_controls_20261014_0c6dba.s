.setcpu "65816"
.segment "CODE"
.org $6DBA
map_control_0c6dba:
    .byte $D3 ; same-value copy count/distance
    .byte $E1 ; previous-row copy count
    .byte $F1 ; progressive-copy count
    .byte $E0 ; previous-row copy escape
    .byte $0F ; row-distance/count
