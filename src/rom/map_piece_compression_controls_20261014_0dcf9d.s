.setcpu "65816"
.segment "CODE"
.org $CF9D
map_control_0dcf9d:
    .byte $E0 ; previous-row copy escape
    .byte $3D ; row-distance/count
