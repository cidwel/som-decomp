.setcpu "65816"
.segment "CODE"
.org $BBC5
map_control_0fbbc5:
    .byte $E0 ; previous-row copy escape
    .byte $0D ; row-distance/count
