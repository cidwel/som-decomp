.setcpu "65816"
.segment "CODE"
.org $D3C3
map_control_0fd3c3:
    .byte $E0 ; previous-row copy escape
    .byte $0D ; row-distance/count
