.setcpu "65816"
.segment "CODE"
.org $50A1
map_control_0c50a1:
    .byte $E0 ; previous-row copy escape
    .byte $0D ; row-distance/count
