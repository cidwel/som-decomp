.setcpu "65816"
.segment "CODE"
.org $369A
map_control_0f369a:
    .byte $D4 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $0C ; row-distance/count
