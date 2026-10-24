.setcpu "65816"
.segment "CODE"
.org $5CA4
map_control_0c5ca4:
    .byte $E0 ; previous-row copy escape
    .byte $0D ; row-distance/count
