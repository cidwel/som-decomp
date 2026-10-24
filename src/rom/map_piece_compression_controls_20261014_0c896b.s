.setcpu "65816"
.segment "CODE"
.org $896B
map_control_0c896b:
    .byte $E0 ; previous-row copy escape
    .byte $0E ; row-distance/count
