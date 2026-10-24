.setcpu "65816"
.segment "CODE"
.org $042C
map_control_0e042c:
    .byte $E0 ; previous-row copy escape
    .byte $0D ; row-distance/count
