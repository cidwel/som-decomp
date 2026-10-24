.setcpu "65816"
.segment "CODE"
.org $FB58
map_control_0dfb58:
    .byte $E0 ; previous-row copy escape
    .byte $0D ; row-distance/count
