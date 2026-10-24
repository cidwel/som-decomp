.setcpu "65816"
.segment "CODE"
.org $9816
map_control_0f9816:
    .byte $E0 ; previous-row copy escape
    .byte $0D ; row-distance/count
