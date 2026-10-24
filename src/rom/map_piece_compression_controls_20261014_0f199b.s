.setcpu "65816"
.segment "CODE"
.org $199B
map_control_0f199b:
    .byte $E0 ; previous-row copy escape
    .byte $0D ; row-distance/count
